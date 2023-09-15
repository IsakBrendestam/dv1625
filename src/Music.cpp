#include "Music.h"

Music::Music(const char* file)
{
    AudioPlayer* ap = AudioPlayer::file(file);

    if(!ap) {
        std::cout << "failed loading music file" << std::endl;
    }
    
    ap->play();
}



void Music::Update()
{
    CFRunLoopRunInMode (                           // 6
        kCFRunLoopDefaultMode,                     // 7
        0.25,                                      // 8
        false                                      // 9
    );
}

