cmake_minimum_required(VERSION 3.25.1)

project(
  Juniorpen01sHttpServer
  LANGUAGES C
  VERSION 0.1.0
  DESCRIPTION "An HTTP server made \"from scratch.\""
  HOMEPAGE_URL https://github.com/juniorpen01/c-juniorpen01s-http-server)

add_subdirectory(app)
add_subdirectory(core)
