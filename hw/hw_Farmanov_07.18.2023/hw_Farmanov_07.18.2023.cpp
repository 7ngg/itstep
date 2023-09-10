#include <iostream>
#include <regex>

int main(int, char**){
    std::regex URL ("\\bhttps?://[a-zA-Z0-9.-]+\\.[/[a-zA-Z0-9/?%&=.-]*]?");
    std::regex DATE ("\\d{2}\\.\\d{2}\\.\\d{4}");
    std::regex HTML_TAG ("<[^>]+>[a-zA-Z0-9]+</[^>]+>");

    std::cout << std::regex_match("https://html5book.ru/html-tags/", URL) << std::endl;
    std::cout << std::regex_match("22.06.2000", DATE) << std::endl;
    std::cout << std::regex_match("<title>1337abc</title>", HTML_TAG) << std::endl;
    
    return 0;
}
