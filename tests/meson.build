cmtest_sources = [
    'main.cpp',
    'cm_map_tests.cpp'
]

cmtest = executable('cmtest', 
    cmtest_sources, 
    include_directories : libcm_includes,
    dependencies : [libzstd_dep, catch2_dep])

test('compress-me unit tests', cmtest)
