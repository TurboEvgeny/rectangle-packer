# rectangle-packer
packing rectangles into containers

#### Требования:
- c++14 compatible компилятор
#### Замечание
- данная программа использует лишь углы поворота в 45, 90 и 145 градусов
- для считывания данных из cin используется scanf, которую visual studio считает небезопасной, так как рекомендуемая scanf_s не кроссплатформенная (основная рабочая среда у меня linux/gcc). Чтобы код собирался в среде VS2019 пришлось включить директиву _CRT_SECURE_NO_WARNINGS

#### Сборка:
##### 1й вариант (cmake). (рекомендуемый путь) 
- установить последний дистрибутив программы cmake
 https://cmake.org/download/
- Далее в программе cmake-gui в поле "where is the source code"
указать путь до папки src данного проекта (например H:/Projects/rectangle-packer/src)
- в поле "where to build the binaries" указать желаемый путь для генерации сборочных файлов
(например H:/Projects/rectangle-packer/bld)
- нажмите кнопку Configire, появится новое окно, 
в поле "Specify the generator for this project" выберите используемую среду разработку,
нажмите кнопку "Finish", если все успешно, то появится надпись "Configuring done"
- нажмите кнопку "Generate", дождитесь надписи Generating done 
- чтобы открыть проект нажмите "Open Project", либо пройдите в папку для сборки

##### 2й вариант (Visual studio 2019)
- в проекте лежат sln и vcproj файлы для IDE Visual Stuido 2019
