cml_sources = run_command(
    'sh', '-c',
    'find "' + meson.current_source_dir()
    + '" -maxdepth 6 \\( -name "*.cpp" -o -name "*.c" \\)',
    check: true
).stdout().strip().split('\n')

cml_dep = declare_dependency(
    sources: cml_sources,
    include_directories: include_directories('.', 'includes'),
    dependencies: lua_dep,
)