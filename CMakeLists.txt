cmake_minimum_required(VERSION 2.8.11)

project(cutecw)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Xml REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

qt5_wrap_ui(UI_HEADERS AboutDialog.ui)
qt5_add_resources(UI_RESOURCES cutecw.qrc)

set(SRCFILES
        main.cpp
        MainWindow.cpp
        Morse.cpp
        Generator.cpp
        MorseStat.cpp
        Prefs.cpp
        modes/SpeedTrainingMode.cpp
        modes/TrainingMode.cpp
        modes/MorseMode.cpp
        modes/PlayMode.cpp
        modes/LetterTrainingMode.cpp
        modes/WordTrainingMode.cpp
        modes/ReadMode.cpp
        modes/ChooseSequenceDialog.cpp
        modes/GroupingMode.cpp
        modes/KeyTraining.cpp
        modes/games/MGameMode.cpp
        modes/games/MCountGameMode.cpp
        modes/games/MTimeGameMode.cpp
        modes/games/GroupGame.cpp
        modes/games/WordGame.cpp
        modes/games/HighScoresDialog.cpp
        modes/games/HighScores.cpp
        modes/QModeStart.cpp
        AboutDialog.cpp
        modes/FrontPage.cpp
        GoalBar.cpp
        widgets/KeyTimingDisplay.cpp
        KeyingReader.cpp
        modes/games/KeyInvaders.cpp
        modes/games/Invader.cpp
        modes/MSequences.cpp
        )


add_executable(cutecw ${SRCFILES} ${UI_HEADERS} ${UI_RESOURCES})
target_link_libraries(cutecw Qt5::Widgets Qt5::Multimedia Qt5Xml)
