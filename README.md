# f2
*An implementation of the direct stiffness method for linear analysis of planar frames.*

<!--[Getting started](README.md#getting-started) | [FAQ](README.md#faq) For later; README is currently too small to benefit from this.-->

This repository is intended to host the underlying logic needed for the calculation, as well as a simple CLI. GUI frontends will be hosted on their own, even if directly referencing to this library.

## Getting started
### Setup
Run "make"; "make clean" to delete the program.

Until otherwise specified, the default will be to compile without any optimisations, with debugging information, and to run the tests afterwards.

### Usage
***The following represents the current design intent, and is not yet implemented!***

Run **f2** with at least two arguments: one *.f2g* file, which includes all the geometrical definitions; and, at least, one *.f2l* file, defining a single load case.

In the end, a quick summary of the calculation is shown in the terminal, with more detailed descriptions being writen to output files. Should more than one load case be input, these conclusions include both results for each given load case, and a single, unfactored, result combination of all of included cases.

## FAQ
### Why?
There are two main motivations for this endeavour: firstly, the desire to procude a "non-trivial" project to help me develop my software development skills; it also has the long term goal of becoming an alternative to an educational tool that existed at the time I was studying structural engineering (which seems to have since gone behind a registration paywall).
