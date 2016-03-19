from glob import glob
from bar_chart import plot_bar

a = []
a += glob("*/results*.txt")
a += glob("*/*/results*.txt")
a += glob("*/*/bin/*/results*.txt")
print(a)
print(len(a))
b = glob("./**//results*.txt")
print(b)
print(len(b))

langs = []


def getLang(path):
    return path.split("\\")[0].split("Uber_Duper_Simulation_")[1].replace("_", " ").replace("Sharp", "#").replace("pp",
                                                                                                                  "++")
    # .replace("Delphi XE2", "Delphi")


def get_data(files, p_languages=None):
    total_data = []
    languages = []

    if p_languages is not None:
        languages = p_languages

    for path_to_file in files:
        file = open(path_to_file, "r")

        if p_languages is None:
            lang = getLang(path_to_file)
            languages.append(lang)

        lines = [line.replace(",", ".").strip() for line in file.readlines()]

        if len(lines) == 6:
            data = [float(line) for line in lines]
        else:
            if len(lines) < 12:
                print(path_to_file, len(lines))

            assert (len(lines) >= 12)
            data = [float(lines[i]) for i in [1, 3, 5, 7, 9, 11]]

        total_data.append(data)
        assert (len(data) == 6)

        file.close()

    return total_data, languages


for file in a:
    lang = getLang(file)
    if lang not in langs:
        langs.append(lang)
print(langs)

print(len(langs))

files = [
    'Uber_Duper_Simulation_Delphi\\results.txt',
    'Uber_Duper_Simulation_Delphi_XE2\\results.txt',
    'Uber_Duper_Simulation_Java\\results.txt',
    'Uber_Duper_Simulation_Julia\\results.txt',
    'Uber_Duper_Simulation_Mathcad\\results.txt',
    'Uber_Duper_Simulation_Mathematica_Runge_Kutta\\results_Runge_Kutta.txt',
    'Uber_Duper_Simulation_Mathematica_Default\\results_Default.txt',
    # 'Uber_Duper_Simulation_Mathematica\\results.txt',
    # 'Uber_Duper_Simulation_Mathematica_Default\\results.txt',
    # 'Uber_Duper_Simulation_Matlab\\results.txt',
    'Uber_Duper_Simulation_Matlab\\results_2015a_64_bit.txt',
    'Uber_Duper_Simulation_Python\\results.txt',
    'Uber_Duper_Simulation_R\\results_32_bit_compiler_enableJIT_3.txt',
    # 'Uber_Duper_Simulation_R\\results_32_bit_no_flag.txt',
    # 'Uber_Duper_Simulation_R\\results_64_bit_compiler_enableJIT_3.txt',
    # 'Uber_Duper_Simulation_R\\results_64_bit_no_flag.txt',
    'Uber_Duper_Simulation_Cpp\\Release\\results.txt',
    # 'Uber_Duper_Simulation_Cpp\\Uber_Duper_Simulation_Cpp\\results.txt',
    # 'Uber_Duper_Simulation_CSharp\\Uber_Duper_Simulation_CSharp\\bin\\Debug\\results.txt',
    'Uber_Duper_Simulation_CSharp\\Uber_Duper_Simulation_CSharp\\bin\\Release\\results.txt',
    # 'Uber_Duper_Simulation_FSharp\\Uber_Duper_Simulation_FSharp\\bin\\Debug\\results.txt',
    'Uber_Duper_Simulation_FSharp\\Uber_Duper_Simulation_FSharp\\bin\\Release\\results.txt',
    # 'Uber_Duper_Simulation_Visual_Basic\\Uber_Duper_Simulation_Visual_Basic\\bin\\Debug\\results.txt',
    'Uber_Duper_Simulation_Visual_Basic\\Uber_Duper_Simulation_Visual_Basic\\bin\\Release\\results.txt',
    # 'Uber_Duper_Simulation_Python\\results_pypy.txt'
    'Uber_Duper_Simulation_Python_PyPy\\results_pypy.txt',
    'Uber_Duper_Simulation_Haskell\\results_Haskell2.txt',
    'Uber_Duper_Simulation_Haxe\\results_html5_44.txt',
    'Uber_Duper_Simulation_JavaScript\\results_Chrome_44.txt',
    'Uber_Duper_Simulation_Fortran\\results2.txt',
]

from pylab import *
import os

for file1 in glob("*.png"):
    os.remove(file1)

total_data, languages = get_data(files)

languages = [l.replace("Haxe", "Haxe/JS") for l in languages]

#по отношению к С++
plot_bar('Производительность решения ОДУ (%)', [data[2] for data in total_data], languages,
         True, 'Производительность', units='%', after_text='\n(чем больше, тем лучше)')
# plot_bar('Тест записи в файл\n по отношению к самой быстрой реализации (чем меньше, тем лучше)', [data[5] - data[2] for data in total_data], languages, True)

plot_bar('Производительность решения ОДУ', [data[2] for data in total_data],
         languages, False, 'Количество расчетов в секунду\n(чем больше, тем лучше)')

data2 = [data[5] for data in total_data]
for lang, value, value2, delta in zip(languages, [data[2] for data in total_data], data2, [data[5] - data[2] for data in total_data]):
    print(lang.replace(" ", "_"), "%.3f %.3f %.3f" % (value, value2, delta))

# exit()

data2 = [data[5] - data[2] for data in total_data]

data3 = []
languages2 = []

for n,l in zip(data2, languages):
    if (n > 0):
        data3.append(n)
        languages2.append(l)


plot_bar('Тест записи в файл\n(чем меньше, тем лучше)', data3, languages2, False)

files = [
    'Uber_Duper_Simulation_Delphi\\results.txt',
    'Uber_Duper_Simulation_Delphi_XE2\\results.txt',
    'Uber_Duper_Simulation_Java\\results.txt',
    'Uber_Duper_Simulation_Julia\\results.txt',
    'Uber_Duper_Simulation_Mathcad\\results.txt',
    'Uber_Duper_Simulation_Cpp\\Release\\results.txt',
    'Uber_Duper_Simulation_CSharp\\Uber_Duper_Simulation_CSharp\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_FSharp\\Uber_Duper_Simulation_FSharp\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_Visual_Basic\\Uber_Duper_Simulation_Visual_Basic\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_Python_PyPy\\results_pypy.txt',
    'Uber_Duper_Simulation_Haxe\\results_html5_44.txt',
    'Uber_Duper_Simulation_JavaScript\\results_Chrome_44.txt',
]

total_data, languages = get_data(files)

languages = [l.replace("Haxe", "Haxe/JS") for l in languages]

plot_bar('%d лучших языков программирования отобранных по критерию производительности\n(чем меньше, тем лучше)' % len(files), [data[2] for data in total_data],
         languages, False)

files = [
    'Uber_Duper_Simulation_Delphi\\results.txt',
    'Uber_Duper_Simulation_Delphi_XE2\\results.txt',
    'Uber_Duper_Simulation_Java\\results.txt',
    'Uber_Duper_Simulation_Cpp\\Release\\results.txt',
    'Uber_Duper_Simulation_CSharp\\Uber_Duper_Simulation_CSharp\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_Visual_Basic\\Uber_Duper_Simulation_Visual_Basic\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_Python_PyPy\\results_pypy.txt',
    'Uber_Duper_Simulation_Haxe\\results_html5_44.txt',
    'Uber_Duper_Simulation_JavaScript\\results_Chrome_44.txt',
]

total_data, languages = get_data(files)

languages = [l.replace("Haxe", "Haxe/JS") for l in languages]

plot_bar('%d лучших языков программирования отобранных по критерию производительности\n(чем меньше, тем лучше)' % len(files), [data[2] for data in total_data],
         languages, False)


files = [
    'Uber_Duper_Simulation_Delphi\\results.txt',
    'Uber_Duper_Simulation_Delphi_XE2\\results.txt',
    'Uber_Duper_Simulation_Java\\results.txt',
    'Uber_Duper_Simulation_Cpp\\Release\\results.txt',
    'Uber_Duper_Simulation_CSharp\\Uber_Duper_Simulation_CSharp\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_Visual_Basic\\Uber_Duper_Simulation_Visual_Basic\\bin\\Release\\results.txt',
    'Uber_Duper_Simulation_Haxe\\results_html5_44.txt',
    'Uber_Duper_Simulation_JavaScript\\results_Chrome_44.txt',
]

total_data, languages = get_data(files)

languages = [l.replace("Haxe", "Haxe/JS") for l in languages]

plot_bar('%d лучших языков программирования отобранных по критерию производительности\n(чем меньше, тем лучше)' % len(files), [data[2] for data in total_data],
         languages, False)

plot_bar('%d лучших языков программирования отобранных по критерию производительности\n(чем меньше, тем лучше) ' % len(files), [data[2] for data in total_data],
         languages, True)

line_count = {
    "Python": 106,
    "Julia": 114,
    "Java": 164,
    "Delphi": 209,
    "Mathematica": 30,
    "C++": 164,
    "Visual Basic": 142,
    "C#": 183,
    "F#": 81,
    "Mathcad": 43,
    "Matlab": 54,
    "R": 134,
    "JavaScript": 136,
}

languages, data = list(line_count.keys()), list(line_count.values())
plot_bar('Объем кода (количество строк)\n(чем меньше, тем лучше)', data, languages, ylabel="Количество строк",
         units=None)

memory_usage = {
    "Mathematica": 811.223,
    "Matlab": (356084 - 238876) / (2 ** 10),
    "C#": 11.04296875,
    "C++": 2.1640625,
    "Visual Basic": 11.90625,
    "F#": 13.3671875,
    "Java": 146.76953125,
    "Julia": 109.19921875,
    "Python": 5.49609375,
    "R": 8.140625,
    "Mathcad": 165.57421875,
    "Delphi 6": 2.90625,
    "Delphi XE2": 3.203125,
}

languages, data = list(memory_usage.keys()), list(memory_usage.values())
plot_bar('Рабочий набор памяти (пик)\n(чем меньше, тем лучше)', data, languages, ylabel="Рабочий набор памяти (пик)",
         units="MB")

files = [
    'Uber_Duper_Simulation_R\\results_32_bit_compiler_enableJIT_3.txt',
    'Uber_Duper_Simulation_R\\results_32_bit_no_flag.txt',
    'Uber_Duper_Simulation_R\\results_64_bit_compiler_enableJIT_3.txt',
    'Uber_Duper_Simulation_R\\results_64_bit_no_flag.txt',
]

languages = [
    "R 32 bit enableJIT(3)",
    "R 32 bit",
    "R 64 bit enableJIT(3)",
    "R 64 bit",
]

total_data, languages = get_data(files, languages)

plot_bar('R 3.22 тест производительности решения ОДУ (dt = 0.01 с)\n(чем меньше, тем лучше)',
         [data[2] for data in total_data], languages, False)

plot_bar('R 3.22 тест производительности решения ОДУ (dt = 0.01 с) \n(чем меньше, тем лучше)',
         [data[2] for data in total_data], languages, True)

files = [
    '.\\Uber_Duper_Simulation_Haxe\\results_as3_release.txt',
    '.\\Uber_Duper_Simulation_Haxe\\results_html5_44.txt',
    '.\\Uber_Duper_Simulation_Haxe\\results_neko.txt',
    '.\\Uber_Duper_Simulation_Haxe\\results_Cpp.txt'
]

languages = [
    "Haxe/AS3",
    "Haxe/JS (Chrome 44)",
    "Haxe/Neko",
    "Haxe/C++",
]

total_data, languages = get_data(files, languages)

plot_bar('Haxe 3.1.3 тест производительности решения ОДУ (dt = 0.01 с)\n(чем меньше, тем лучше)',
         [data[2] for data in total_data], languages, False)

files = [
    '.\\Uber_Duper_Simulation_Delphi\\results.txt',
    '.\\Uber_Duper_Simulation_Delphi_XE2\\results.txt',
]

languages = [
    "Delphi 6",
    "Delphi XE2",
]

total_data, languages = get_data(files, languages)

plot_bar('Delphi тест производительности решения ОДУ (dt = 0.01 с)\n(чем меньше, тем лучше)',
         [data[2] for data in total_data], languages, False)

plot_bar('Delphi тест записи в файл\n(чем меньше, тем лучше)',
         [data[5] for data in total_data], languages, False)

delphi_compilers_test = {
    "Turbo Pascal 7 (Windows XP Mode)": 10.022,
    "Delphi 6": 1.154,
    "Delphi XE2": 1.188,
    "Free Pascal Compiler": 0.966,
}

languages, data = list(delphi_compilers_test.keys()), list(delphi_compilers_test.values())
plot_bar('Тест производительности компиляторов\nязыка Delphi (Object Pascal)', data, languages,
         ylabel="Время выполнения")
plot_bar('Тест производительности компиляторов \nязыка Delphi (Object Pascal)', data, languages,
         norm = True, ylabel="Время выполнения")

languages = [
    "Python 3.4",
    "Python 2.7.10",
    "Python 2.7.10\nCython 0.22",
    "PyPy 4.0.1",
]

files = [
    'Uber_Duper_Simulation_Python\\results.txt',
    'Uber_Duper_Simulation_Python\\results_2_7.txt',
    'Uber_Duper_Simulation_Python\\results_2_7_cython.txt',
    'Uber_Duper_Simulation_Python_PyPy\\results_pypy.txt'
]

total_data, languages = get_data(files, languages)

plot_bar('Python тест производительности решения ОДУ (dt = 0.01 с)\n(чем меньше, тем лучше)',
         [data[2] for data in total_data], languages, False)

plot_bar('Python тест производительности решения ОДУ (dt = 0.01 с) \n(чем меньше, тем лучше)',
         [data[2] for data in total_data], languages, True)

# plot([i for i in range(0, len(total_data))], total_data)

# show()

cpp = 'Uber_Duper_Simulation_Cpp\\Uber_Duper_Simulation_Cpp\\Uber_Duper_Simulation_Cpp.cpp'
f = open(cpp, 'r+')
sourceFileData = f.read()
# print(sourceFileData)

line_length = []
sum = 0

for line in sourceFileData.split("\n"):
    line_strip = line.strip()
    n = len(line_strip)
    if not line_strip.startswith("//") and n > 0:
        line_length.append(n)
        print(line, n)
        sum += n

min_line_length = min(line_length)
max_line_length = max(line_length)

average_line_length = sum / len(line_length)

print(min_line_length, max_line_length, average_line_length)

