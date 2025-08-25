#include <botan/block_cipher.h>
#include <iostream>
#include <QtCore/qdebug.h>
#include "internal/widevine/widevine_protocol.pb.h"

int main() {
  std::unique_ptr<Botan::BlockCipher> sessionKeyBlock = Botan::BlockCipher::create_or_throw("AES-128");
  SignedLicenseRequest signedLicenseRequest = SignedLicenseRequest();
  std::cout << "Hello, World!" << std::endl;
  qDebug() << "Hello Qt!\n";
  return 0;
}
