project('compress-data-struct-cpp', 
    'cpp', 
    version: '0.1.0',
    default_options : ['cpp_std=c++17', 'default_library=both'], 
    license: 'MIT')

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
configure_file(input : 'src/config.h.in',
               output : 'config.h',
               configuration : conf_data)

src_include = include_directories('./src')

# zstd subproject
subproject ('zstd')
zstd = dependency('zstd_dep', fallback : ['zstd', 'zstd_dep'])

# executable('compress-data-struct-cpp', 'src/core/example.cpp')
src = [ 
    'src/unordered_set_compressed.cpp', 
    'src/core/example.cpp'
    ]
library(src, dependencies: [zstd], include_directories : src_include)
