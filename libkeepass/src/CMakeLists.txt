cmake_minimum_required(VERSION 3.15)
project(keepasslib)

include_directories( src )

add_library( keepasslib
        cipher.cc
        entry.cc
        group.cc
        io.cc
        kdb.cc
        kdbx.cc
        key.cc
        metadata.cc
        pugixml.cc
        random.cc
        stream.cc
        util.cc
)
