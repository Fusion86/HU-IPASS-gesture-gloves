#!/usr/bin/env python3

import sys
from spotify_local import SpotifyLocal

spotify = SpotifyLocal()
is_paused = True

for xline in sys.stdin:
    line = xline.rstrip()
    print(line)

    if ("action:" in line):
        action = line.split(":")[1].strip()
        print("FOUND ACTION: " + action)
        if ("toggle_play_pause" in action):
            spotify.pause(is_paused)
            is_paused = not is_paused
        elif ("volume_up" in action):
            pass
        elif ("volume_down" in action):
            pass