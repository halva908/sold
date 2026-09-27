#include <iostream>
#include <fstream>
#include <string>

class Printable {
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
};

class TextData : public Printable {
public:
    explicit TextData(std::string data) : data_(std::move(data)) {}
    std::string print() const override {
        return data_;
    }
private:
    std::string data_;
};

class HTMLData : public Printable {
public:
    explicit HTMLData(std::string data) : data_(std::move(data)) {}
    std::string print() const override {
        return "<html>" + data_ + "</html>";
    }
private:
    std::string data_;
};

class JSONData : public Printable {
public:
    explicit JSONData(std::string data) : data_(std::move(data)) {}
    std::string print() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }
private:
    std::string data_;
};

void saveTo(std::ostream& os, const Printable& printable) {
    os << printable.print() << std::endl;
}

void saveToAsHTML(std::ostream& os, const HTMLData& printable) {
    saveTo(os, printable);
}

void saveToAsJSON(std::ostream& os, const JSONData& printable) {
    saveTo(os, printable);
}

void saveToAsText(std::ostream& os, const TextData& printable) {
    saveTo(os, printable);
}

int main() {
    TextData myText("Hello World");
    HTMLData myHtml("Hello World");
    JSONData myJson("Hello World");

    std::cout << "Output to console:" << std::endl;
    saveToAsText(std::cout, myText);
    saveToAsHTML(std::cout, myHtml);
    saveToAsJSON(std::cout, myJson);


    return 0;
}