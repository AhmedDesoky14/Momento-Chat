//#include <cstdio>
#include "server_messages.pb.h"

#include <vector>
#include "keys.h"
#include "certificates.h"
#include "utils.h"

int main()
{
    InitOpenSSL();
    //printf("hello from %s!\n", "sandbox2");
    RSA_key newprivkey;
    std::vector<unsigned char> vect = newprivkey.SerializeKey();
    //std::string path = "/home/desoky/Fade_Project/keys/server-key.pem";
    //RSA_key serverprivkey(path);
    //RSA_key serverpubkey = serverprivkey.DerivePublicKey();
    //std::string cert_storepath = "/home/desoky/Fade_Project/keys/server-cert.pem";
    //X509_certificate server_cert(cert_storepath, std::make_shared<RSA_key>(serverpubkey), std::make_shared<RSA_key>(serverprivkey));
    //server_cert.SignCertificate(std::make_shared<RSA_key>(serverprivkey));
    //bool is = server_cert.isCertificateSigned(std::make_shared<RSA_key>(serverpubkey));
    //std::string serialn = server_cert.GetSerial();
    return 0;
}