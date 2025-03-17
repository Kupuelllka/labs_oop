# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-src"
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-build"
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix"
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/tmp"
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp"
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src"
  "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/dmitry/labs_oop/stl/1/_deps/nanobench-subbuild/nanobench-populate-prefix/src/nanobench-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
