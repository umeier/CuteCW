#include <qdebug.h>

#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>

#include "ReadMode.h"
#include "Morse.h"

ReadMode::ReadMode(Morse *parent, Ui::MainWindow *ui)
    : MorseMode(parent, ui)
{
}

void
ReadMode::switchToMode() {
    m_ui->wordbox->show();
    m_ui->modeMenu->setText("Read to me!");
    m_ui->helpBar->setText("<font color=\"green\">Enter text and hit the play button to hear the entire sequence.</font>");
    m_ui->play->show();
    clear();
    addButtons();
}

void
ReadMode::addButtons() {
    QPushButton *button = new QPushButton(tr("Load File"));
    m_ui->forModes->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(openFile()));
}

void
ReadMode::openFile() {
    QString fileName = QFileDialog::getOpenFileName(0, tr("Load a file"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QString contents = file.readAll();
    if (contents.isEmpty()) {
        QMessageBox::critical(0, tr("Failed to read file"), tr("Opening file %1 failed").arg(fileName));
        return;
    }
    m_ui->wordbox->setText(contents);
}

void ReadMode::play() {
    QTextCursor readSpot = m_ui->wordbox->textCursor();
    readSpot.select(QTextCursor::Document);

    m_morse->add(readSpot.selectedText());
    m_morse->playSequence();
    return;
    //qDebug() << "starting to read";
    //m_readSpot = m_ui->wordbox->cursorForPosition(QPoint(0,0));
    //readNextLetter();
}

void ReadMode::readNextLetter() {
    if (m_readSpot.atEnd()) {
        qDebug() << "reached the end; stopping playing";
        return;
    }
    // move the anchor to where the cursor is
    m_readSpot.movePosition(QTextCursor::NoMove, QTextCursor::MoveAnchor, 0);
    // move the selection pointer to the right one, highlighting the current
    // selection letter we're going to play
    m_readSpot.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, 1);
    // play the selection
    qDebug() << "playing selected text: " << m_readSpot.selectedText();
    m_morse->addAndPlayIt(m_readSpot.selectedText()[0]);
}

void ReadMode::audioStopped()
{
    qDebug() << "audio stopped method";
    setRunningMode(PAUSED);
}

