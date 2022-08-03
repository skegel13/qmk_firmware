#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define TAPPING_FORCE_HOLD

#define NO_AUTO_SHIFT_ALPHA
