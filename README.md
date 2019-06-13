# The Clone Arcade

This is an app like my command line arcade though this one uses the ncurses C++ library.
I wanted to make the fame Snake Game and decided to give Tetris a try too. The app tries
to be as simple as possible on library use so only ncurses will need to be installed to
compile. This was quite the learning experience as I tried to create my own way to do two
commonly made games. Hope you enjoy my versions of the games more than I did debugging them.

## Notes:

* **IMPORTANT:** The app uses a 80x24 terminal size. I worked in a default size and in the end
felt it was a nice mix between being small, out the way and enough room to operate.
* The simple Makefile is for clang++. Edit to your preference.
* Works for both colored and non-colored terminals.
* There is no unicode used for cross-platform convenience.
* ncurses library is often pre-installed on Unix systems, but I am unsure of windows.
* This was written in Xcode and tested on Mac only so far.
* Did not know Github accepted executables but one is included. **COMPILED ON MAC, USE AT OWN RISK.**

## TODO:

- [ ] Add a feature to save scores.
- [ ] A pause button for the Snake Game.
- [ ] Difficulty levels.

![ArcadeMenu](/images/ArcadeMenu.png)
