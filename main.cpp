#include <iostream>

#include "WebReader.hpp"

int main() {
    WebReader reader;
    reader.openFile("https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media");
    return 0;
}
