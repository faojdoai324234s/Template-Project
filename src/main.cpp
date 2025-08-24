#include <botan/block_cipher.h>
#include <libavformat/avformat.h>
#include <iostream>
#include "internal/widevine/widevine_protocol.pb.h"

int main() {
  std::unique_ptr<Botan::BlockCipher> sessionKeyBlock = Botan::BlockCipher::create_or_throw("AES-128");
  SignedLicenseRequest signedLicenseRequest = SignedLicenseRequest();
  AVFormatContext* pFormatContext = avformat_alloc_context();
  if (!pFormatContext) {
    return -1;
  }
  avformat_close_input(&pFormatContext);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
