#include <iostream>

extern "C" {
#include <libavformat/avformat.h>
}

int main() {
  AVFormatContext* av_format_ctx = NULL;
  if (!(av_format_ctx = avformat_alloc_context())) {
      return -1;
    }
  avformat_free_context(av_format_ctx);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
