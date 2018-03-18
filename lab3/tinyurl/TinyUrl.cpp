#include "TinyUrl.h"

namespace tinyurl {
    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> first_object = std::make_unique<TinyUrlCodec>();
        first_object->hash = {'0','0','0','0','0','0'};
        return first_object;
    }

    void NextHash(std::array<char, 6> *state) {
        std::string alfabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        unsigned long indeks, i=5;
        while(state->at(i)=='z'){
            state->at(i)='0';
            i--;
        }
        indeks=alfabet.find(state->at(i));
        state->at(i)=alfabet.at(indeks+1);
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        NextHash(&codec->get()->hash);
        std::string hash;
        for (auto letter: codec->get()->hash)
            hash += letter;
        codec->get()->m=url;
        return hash;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        std::string url=codec->m;
        return url;
    }
}