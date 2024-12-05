#ifndef TAPE_H
#define TAPE_H
#include <QString>
#include <QVector>
class tape {
public:
    tape(const QString& name, int totalLength);
    //Manage audio files
    void addAudioFile(const QString& filePath,int length);
    void removeAudioFile(int index);

    //getters
    int getRemainingLength() const;     //Get the remaining length of the cassette
    QVector<QString> getAudioFiles() const;
    QVector<int> getFileLengths() const;
    QString getName () const;

    //GetTapeLength
    int getTapeLength() const;
    int getSideLength() const;
    void exportToWAV(const QString& side,const QString& tmpDir, const QString& outDir) const;);

private:
    QString tapeName;
    int totalLength;
    int usedLength;
    QVector<QString> audioFiles;
    QVector<int> fileLengths;
};

#endif // TAPE_H
