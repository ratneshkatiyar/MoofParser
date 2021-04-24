#include "boxes.hpp"
#include "utility.hpp"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <curl/curl.h>
int Boxes::parseElements(std::ifstream &input, const uint64_t totalSize)
{
    uint32_t boxSize = 0;
    char boxTypeBuffer[4]{0};
    char boxSizeBuffer[4]{0};
    int result{0};
    if (!input or totalSize == 0)
    {
        return -1;
    }
    while (true)
    {
        if (!input.good())
        {
            return -1;
        }
        // readbox size
        constexpr auto readBoxSize = 4;
        input.read(boxSizeBuffer, readBoxSize);

        boxSize = (static_cast<uint8_t>(boxSizeBuffer[0]) << 24) + (static_cast<uint8_t>(boxSizeBuffer[1]) << 16) + (static_cast<uint8_t>(boxSizeBuffer[2]) << 8) + static_cast<uint8_t>(boxSizeBuffer[3]);

        //readboxtype
        constexpr auto readBoxType = 4;
        input.read(boxTypeBuffer, readBoxType);

        auto box = Factory::create(boxTypeBuffer);
        box->m_boxSize = boxSize;
        //for moof and traf
        if (box->m_boxtype == MoofBoxes::MOOF or box->m_boxtype == MoofBoxes::TRAF)
        {
            result = box->parseElements(input, totalSize);
        } // for mdat
        else if (box->m_boxtype == MoofBoxes::MDAT)
        {
            std::stringstream sstream;
            sstream << input.rdbuf();
            box->setMediaDataBoxData(sstream.str());
        }
        else
        { // to find some other box

            input.seekg(box->m_boxSize - box->m_dataReadSoFar, std::ios::cur);
        }
        m_dataReadSoFar += box->m_boxSize;

        elements.emplace_back(std::move(box));
        constexpr auto initialByteRead = 8;
        if (m_dataReadSoFar - initialByteRead == totalSize)
        {
            break;
        }
        if (m_dataReadSoFar == m_boxSize)
            break;
        if (result < 0)
            return result;
    }
    return 0;
}
void Boxes::setMediaDataBoxData(const std::string &mdatData)
{
    m_mdatBoxData = mdatData;
}
void Boxes::setBoxType(const std::string &type)
{
    m_boxtype = type;
}

std::string Boxes::getMediaDataBoxData() const
{
    return m_mdatBoxData;
}

void Boxes::displayMsg(std::ostream &os)
{
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        os << "Found box of type " << (*it)->m_boxtype << " and size " << (*it)->m_boxSize << std::endl;
        (*it)->displayMsg(os);
    }
}
bool Boxes::downloadFile(char **argv)
{
    CURL *curl;
    FILE *fp;
    CURLcode result;
    fp = fopen(argv[2], "wb");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    result = curl_easy_perform(curl);
    if (result == CURLE_OK)
    {
        curl_easy_cleanup(curl);
        fclose(fp);
        return true;
    }
    else
    {
        std::cout << "Error while downloading file:" << curl_easy_strerror(result)
                  << std::endl;
        return false;
    }
}