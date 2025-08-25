#include <cstdio>
#include <iostream>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

int main() {
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
