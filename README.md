# Moof Parser

C++ Application that parses moof box and finds and prints mdat and other box content.
It is tested and worked on Ubuntu 20.04. It also extracts the MDAT box base-64 encoded Images.

## Setup

This project contains google test also and to build google test and application follow the build Instruction

## Building and Running

mkdir build
cd build
cmake ..
make -j4
./moofparser https://demo.castlabs.com/tmp/text0.mp4 test0.mp4

## Libraries

libcurl : to download http content and save in file
rapidxml : to parse xml MDAT content
Cryptopp :  to decode the base64 encoded images.
gtest    : to run unit test cases

## Install Libraries

sudo apt-get install libcurl4-openssl-dev
sudo apt-get install pkg-config

sudo apt install librapidxml-dev -y

sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils

## Devlopment process
*boxes* is a common class and all other classes are derived from it for different box.

Libcurl is used to download the file from http.

*parseElements* function is to parse different boxes

*displayMsg* is to print output on console.

*saveImageToDisk* function is to parse xml in mdat box and decode base64 image.

## Bonus1
traditional fmp4 segment , where mdat box is too large,playback of segment can only start once fully downloaded.
This can add latency and player has to wait until the complete mdat box downloaded and parsed which is not decent in live streaming.
The solution is CMAF segment, where chunks are very small and contain moof and mdat data to achieve subsecond latency.

## Bonus2
 Implemented inside *saveImageToDisk* function

## Output 

Output of this app is stored in Output.png file
Mdat box base64 decode images are stored in image001.png, image002.png, image003.png

## To Do
Code can be further optimized and have to add mutliple unit test cases.
