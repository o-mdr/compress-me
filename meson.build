project('compress-data-struct-cpp', 
    'cpp', 
    version: '0.0.1',
    default_options : ['cpp_std=c++11', 'default_library=both'], 
    license: 'MIT or GNU GPLv2')

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
configure_file(input : 'src/config.h.in',
               output : 'config.h',
               configuration : conf_data)

libcdsc_includes = include_directories('src')

# Subprojects
subproject ('zstd')
zstd = dependency('libzstd_dep', fallback : ['zstd', 'libzstd_dep'])

subproject ('catch2')
catch2 = dependency('catch2_dep', fallback : ['catch2', 'catch2_dep'])

# Library
libcdsc = library('cdsc', 
    'src/cdsc.h', 
    dependencies: [zstd, catch2], 
    include_directories : libcdsc_includes)

libcdsc_dep = declare_dependency(link_with: libcdsc,
  include_directories: libcdsc_includes)

# Tests
test_src = [ 
    'tests/main.cpp',
    'tests/compressable_map.cpp'
    ]
cdsc_unit_tests = executable(
    'tests/cdsc_unit_tests',
    test_src,
    include_directories : libcdsc_includes,
    dependencies: [zstd, catch2])
test('cdsc unit tests', cdsc_unit_tests)

# Examples
executable('examples/zstd_map', 'examples/zstd_map.cpp', dependencies: [zstd],
    dependencies: [zstd], include_directories : libcdsc_includes)
