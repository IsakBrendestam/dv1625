#pragma once

#include "../dependencies/vendor/auplay/AudioPlayer.h"
#include <CoreFoundation/CoreFoundation.h>
#include <iostream>

class Music
{
public:
    Music(const char* file);
    void Update();

private:
    const char* m_path;
    AudioPlayer* m_ap;
};