#ifndef MORSE_H
#define MORSE_H

#include <QtCore/QString>
#include <QtMultimedia/QAudioOutput>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtGui/QLabel>
#include <QtCore/QTime>
#include <QtCore/QTimer>
#include <QtGui/QTextCursor>
#include <QtGui/QIcon>
#include <QtCore/QSignalMapper>

#include "Generator.h"
#include "MorseStat.h"

#include "modes/MorseMode.h"

#include "ui_MainWindow.h"
#include "ui_Prefs.h"
#include "ui_AboutDialog.h"

class MainWindow;
class PlayMode;
class MorseMode;

class Morse : public QObject
{
public:
    Q_OBJECT

public:
    Morse();
    Morse(MainWindow *parent, QAudioOutput *output, Ui::MainWindow *ui);

    static const int DEFAULT_TONE = 500;

    enum ditdah{ DIT, DAH, SPACE, PAUSE };

    enum TrainingMode { PLAY, TRAIN, SPEEDTRAIN, WORDS, GROUPS, WORDGAME, GROUPGAME, READ, TEST };
    enum AudioMode { STOPPED, PLAYING, PAUSED };
    enum BadLetterWeighting { LOW = 1, HIGH = 2 };

    void setupWidgets();
    void setupTopButtons(QLayout *parentLayout);
    void createModesMenu(QPushButton *modeButton);
    void setupSequenceLayouts(QVBoxLayout *parentLayout, QWidget *theMainThing);
    void setupWPMLayout(QVBoxLayout *parentLayout, QWidget *theMainThing);
    void setupConnections();

    void setupWords();
    void setupSequences();
    void clearList();

    void createTones(int wpm, int spacewpm = -1, int letterspacewpm = -1);
    void createTones(float ditSecs, int dahMult = 3, int pauseMult = 1, int letterPauseMult = 3, int spaceMult = 7);
    void createSpacedTones(float ditSecs, float spaceSecs, float letterSpaceSecs);

    void add(Generator *nextsound);
    void add(QChar c, bool addpause = true);
    void add(const QString &textToAdd);
    QTime addAndPlayIt(QChar c);
    QTime playIt(QChar c);
    QTime sequenceTime();

    MorseStat *getStat(const QChar &key);

    void handleKeyResponse(QChar letterPressed);
    bool enterPressed();

    Generator *dit();
    Generator *dah();
    Generator *pause();
    Generator *letterPause();
    Generator *space();

    float ditSecs();

    int currentWPMGoal();
    int currentWPMAccept();
    AudioMode audioMode();
    void setAudioMode(AudioMode newmode);
    TrainingMode trainingMode();
    BadLetterWeighting badLetterWeighting();

public slots:

    void playSequence();
    QTime maybePlaySequence(bool addPause = false);

    void generatorDone();
    void audioFinished(QAudio::State state);
    void keyPressed(QString newtext);
    void keyPressed(QChar key);

    void prefsButton();
    void aboutButton();
    void switchMode(int newMode);

    void clearStatsButton();

    void playButton();

    void saveSettings();
    void loadSettings();

    void pauseAudio();
    void playAudio();

public:
    QLabel                          *m_sequenceLabel;
    QMap<QChar, QList<ditdah> *>    code;

    QMenuBar * menuBar();
private:

    void _createTones();

    QMap<TrainingMode, MorseMode *>  m_modes;

    MainWindow                      *m_parent;
    QAudioOutput                    *m_audioOutput;
    float                            m_ditSecs, m_dahSecs, m_pauseSecs, m_letterPauseSecs, m_spaceSecs;
    int                              m_dahMult, m_pauseMult, m_letterPauseMult, m_spaceMult;
    Generator                       *m_dit, *m_dah, *m_space, *m_pause, *m_letterPause;
    Generator                       *m_playBuffer;
    AudioMode                        m_playingMode;
    TrainingMode                     m_gameMode;
    int                              m_currentWPMGoal;
    int                              m_currentWPMAccept;
    Ui::MainWindow                  *m_ui;
    BadLetterWeighting               m_badLetterWeighting;
    QTimer                           m_timer;
    int                              m_tone;

    QSignalMapper                   *m_signalMapper;
};

#endif // MORSE_H
