#include "mediaDataBox.hpp"
#include <vector>
#include "rapidxml/rapidxml.hpp"
#include <crypto++/base64.h>
#include "utility.hpp"
#include <sstream>
using namespace rapidxml;
void MediaDataBox::saveImageToDisk()
{
    auto mdataBox = getMediaDataBoxData();
    std::vector<char> makeXMLCopy(mdataBox.begin(), mdataBox.end());
    makeXMLCopy.emplace_back('\0');
    xml_document<> xmldoc;
    xmldoc.parse<0>(makeXMLCopy.data());
    xml_node<> *metaDataNodePointer = xmldoc.first_node(MediaDataBoxParsing::TT)->first_node(MediaDataBoxParsing::HEAD)->first_node(MediaDataBoxParsing::METADATA);
    if (metaDataNodePointer != 0)
    {
        auto fileNameCount{1};
        std::string imageb64Encoded, decodedImage;
        for (xml_node<> *node = metaDataNodePointer->first_node(); node; node = node->next_sibling())
        {
            imageb64Encoded = node->value();
            //base64 decode
            CryptoPP::StringSource ss((byte *)imageb64Encoded.data(), imageb64Encoded.size(), true,
                                      new CryptoPP::Base64Decoder(
                                          new CryptoPP::StringSink(decodedImage)));

            std::stringstream filename_stream;
            filename_stream << "image00" << fileNameCount << ".png";
            std::string imageFilename = filename_stream.str();
            std::ofstream outputImageFile;
            outputImageFile.open(imageFilename.c_str(), std::ios::out | std::ios::binary);
            if (!outputImageFile)
            {
                std::cout << "Output Image open failed " << std::endl;
            }
            outputImageFile.write(decodedImage.c_str(), decodedImage.size());
            outputImageFile.close();
            fileNameCount++;
        }
    }
    else
    {
        std::cout << "metadata node not found in xml file" << std::endl;
    }
}

void MediaDataBox::displayMsg(std::ostream &os)
{
    os << "Content of mdat box is: " << getMediaDataBoxData() << std::endl;
    saveImageToDisk();
}