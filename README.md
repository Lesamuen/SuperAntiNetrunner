# SuperAntiNetrunner
A Net Architecture Generator for Cyberbunk RED (2019)

Created by Samuel Nguyen and Robert Kubos (2021)

# Change Log
Version 0.4.5 (2021-12-05)
- Set up all basic definitions for floor contents
- Editted some declarations

Version 0.4.0 (2021-11-30)
- Set up all basic declarations for net architecture and contents; next version will see whether these declarations actually work.
- Moved PRNG definition from function call to main program thread, to lower costs.
- Reversed order of changelog to latest to first.
- Replaced endl with \n in many places to lower costs of output.
- Condensed cout buffers to lower costs of output and improve code readability.
- Converted exit(0) to return 0.

Version 0.3.0 (2021-09-18)
- Split single source file into multiple headers and sources
- Removed architecture data structure temporarily; it was too messy.
- Moved everything to GitHub!!!

Version 0.2.0 (2021-03-10)
- Added basic architecture data structure implementation
- Added generation of floor content file data structure
- Added complete generation of floor content and menus for generation
- Implemented default floor content lists from core rulebook
- Started on floor connection generation

Version 0.1.0 (2021-03-06)
- Added function to print the unbranched architecture
- Added class for keeping track of price
- Added int budget so user can set their budget during full build
- Added random roll function

Version 0.0.1 (2021-03-05)
- Made base structure and menus
- Made base outlines for generation