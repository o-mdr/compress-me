project('compress-me', 
    'cpp', 
    version: '0.0.1',
    default_options : ['cpp_std=c++11', 'default_library=both'], 
    license: 'MIT or GNU GPLv2')

libcm_includes = include_directories('src')

# Subprojects
subproject ('zstd')
zstd = dependency('libzstd_dep', fallback : ['zstd', 'libzstd_dep'])

subproject ('catch2')
catch2 = dependency('catch2_dep', fallback : ['catch2', 'catch2_dep'])

# Library
if get_option('enable-lib')
    libcm = library('cm', 
        'src/cm.h', 
        dependencies: [zstd, catch2], 
        include_directories : libcm_includes)

    libcm_dep = declare_dependency(link_with: libcm,
    include_directories: libcm_includes)
endif

# Tests
if get_option('enable-tests')
    test_src = [ 
        'tests/main.cpp',
        'tests/cm_map_tests.cpp'
        ]
    cm_unit_tests = executable(
        'tests/cm_unit_tests',
        test_src,
        include_directories : libcm_includes,
        dependencies: [zstd, catch2])
    test('compress-me unit tests', cm_unit_tests)
endif

# Examples
if get_option('enable-examples')
    executable('examples/zstd_map', 'examples/zstd_map.cpp', dependencies: [zstd],
        dependencies: [zstd], include_directories : libcm_includes)
endif
