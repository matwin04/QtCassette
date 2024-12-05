#include "tape.h"
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDir>
tape::tape(const QString& name, int totalLength) : tapeName(name), totalLength(totalLength), usedLength(0) {}

void tape::addAudioFile(const QString &filePath, int length) {
    if (usedLength + length <= totalLength){
        audioFiles.append(filePath);
        fileLengths.append(length);
        usedLength += length;
    } else {
        throw std::runtime_error("Not enough space put on other side");
    }
}
void tape::removeAudioFile(int index) {
    if (index >= 0 && index < audioFiles.size()){
        usedLength -= fileLengths[index];
        audioFiles.removeAt(index);
        fileLengths.removeAt(index);
    } else {
        throw std::out_of_range("Invalid File");
    }
}

int tape::getRemainingLength() const {
    return totalLength - usedLength;
}

int tape::getTapeLength() const {
    return totalLength;
}

int tape::getSideLength() const {
    return totalLength / 2;
}

QVector<int> tape::getFileLengths() const {
    return fileLengths;
}

