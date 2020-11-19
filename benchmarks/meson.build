cmbenchmark_sources = [
    'main.cpp',
    'cmmap_insert_at.cpp'
]

cmbenchmark = executable('cmbenchmark', 
    cmbenchmark_sources,     
    include_directories : libcm_includes,
    dependencies : [libzstd_dep, google_benchmark_dep])


benchmark('cmmap benchmark', cmbenchmark)
