project('mirage', 'cpp')

lib_src = ['src/MApp.cpp', 'src/Gui/MWindow.cpp']

lib_inc = include_directories('src/')

libmirage = shared_library('mirage',
                           sources : lib_src,
                           include_directories : lib_inc)

executable('test-mirage',
           sources : ['test/main.cpp'],
           include_directories : include_directories(['test/', 'src/']),
           link_args: '-municode',
           link_with : libmirage)
