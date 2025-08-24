#include <botan/block_cipher.h>
#include <cstdio>
#include <iostream>
#include "internal/widevine/widevine_protocol.pb.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

int main() {
  std::unique_ptr<Botan::BlockCipher> sessionKeyBlock = Botan::BlockCipher::create_or_throw("AES-128");
  SignedLicenseRequest signedLicenseRequest = SignedLicenseRequest();
  AVFormatContext* pFormatContext = avformat_alloc_context();
  if (!pFormatContext) {
    return -1;
  }
  avformat_close_input(&pFormatContext);
  const AVCodec* codec = avcodec_find_decoder_by_name("libfdk_aac");
  fprintf(stderr, "Codec id: %d, name %s , long_name: %s \n", codec->id, codec->name, codec->long_name );
  AVCodecContext* context = avcodec_alloc_context3(codec);
  int ret = avcodec_open2(context, codec, NULL);
  fprintf(stderr, "From context: Codec id: %d, name %s , long_name: %s \n", context->codec_id, context->codec_descriptor->name, context->codec_descriptor->long_name);
  avcodec_free_context(&context);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
