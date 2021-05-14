#pragma once

// Used by my userspace code to strip the top row of layouts.
#define ORTHO_4X12

#ifdef AUDIO_ENABLE
    //#define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define STARTUP_SONG SONG(E__NOTE(_C8), E__NOTE(_G8))

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif
