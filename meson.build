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

src_include = include_directories('./src/core')

# zstd subproject
subproject ('zstd')
zstd = dependency('libzstd_dep', fallback : ['zstd', 'libzstd_dep'])

src = [ 
    'src/core/example.cpp'
    ]
library(src, dependencies: [zstd], include_directories : src_include)

executable('demo', src, dependencies: [zstd],
    dependencies: [zstd], include_directories : src_include)
