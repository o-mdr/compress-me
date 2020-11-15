project('compress-me', 
    'cpp', 
    version: '0.0.1',
    default_options : ['cpp_std=c++11', 'default_library=both'], 
    license: 'MIT or GNU GPLv2')

libcm_includes = include_directories('src')

# Subprojects
subproject ('zstd')
libzstd_dep = dependency('libzstd_dep', fallback : ['zstd', 'libzstd_dep'])

# Library
if get_option('enable-lib')
    libcm = library('cm', 
        'src/cm.h', 
        dependencies: [libzstd_dep], 
        include_directories : libcm_includes)

    libcm_dep = declare_dependency(link_with: libcm,
        include_directories: libcm_includes)
endif

# Tests
if get_option('enable-tests')
    subdir('tests')
endif

# Examples
if get_option('enable-examples')
    subdir('examples')
endif
