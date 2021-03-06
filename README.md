### This module has been deprecated. Please use [Islandora Remote Media](https://github.com/bondjimbond/islandora_remote_media).

# Islandora Remote Video Solution Pack

An Islandora Solution Pack that allows for ingesting and viewing videos that are hosted elsewhere on the web, using the video's embed code.

## Introduction

This solution pack manages metadata-only records for Video objects (and probably Audio objects as well) that are hosted elsewhere on the Web.
The media's embed code is stored in the object's OBJ datastream, which is editable if changes need to be made after ingesting. The object's View page is
similar to any other Islandora object, except instead of using Islandora's viewer to display a local object, the page shows an embedded viewer from
the remote resource.

The use case for this solution pack is to make externally-hosted media discoverable in the repository and to expose it to harvesters.
This is particularly useful if storage is expensive, as Islandora video objects and their derivatives have high storage demands.

## Requirements

* [Islandora](https://github.com/Islandora/islandora)

## Maintainer

* [Brandon Weigel](https://github.com/bondjimbond)

## Development and feedback

Bug reports, use cases and suggestions are welcome, as are pull requests. Open an issue in the repository to give feedback.

## License

* [GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
