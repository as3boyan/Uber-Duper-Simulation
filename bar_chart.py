#!/usr/bin/env python
# -*- coding: utf-8 -*-
# a bar plot with errorbars
import matplotlib
import matplotlib.patheffects as path_effects
from pylab import *
from random import random

matplotlib.rc('font', family='Times New Roman')

print(cm.cmap_d.keys())

def plot_bar(title, womenMeans, languages, norm=False, ylabel='Производительность (кол-во расчетов в секунду)', units='', after_text=''):
    # womenMeans = [25, 32, 34, 20, 25]
    # womenMeans = [log10(x) for x in womenMeans]

    # originalMeans = womenMeans.copy()

    womenMeans = [1/mean for mean in womenMeans]

    N = len(womenMeans)
    m = max(womenMeans)

    if m == 0:
        print(title, womenMeans, languages)

    if norm:
        womenMeans = [item / m * 100 for item in womenMeans]

    # languages = ["Matlab", "Delphi", "C++", "C#", "F#"]
    a = zip(womenMeans, languages)
    a = sorted(a, key=lambda lang: lang[0])
    womenMeans, languages = zip(*a)
    ind = np.arange(N)  # the x locations for the groups
    width = 1  # the width of the bars
    fig, ax = plt.subplots()

    k = random() * -0.2
    l = 0.5 * 1.5 + 0.1

    # c = [cm.Accent(((i / N) * (0.05 + l) + k)) for i in range(0, len(womenMeans))]

    # rects1 = ax.bar(ind, [i for i in range(0, len(languages))], width, color=c)
    # womenMeans = (25, 32, 34, 20, 25)
    # womenStd = (3, 5, 2, 3, 3)
    # k, l = 0.07262484353752824, 0.024258206040663935 #+ 0.15
    # print(k, l)

    # 0.00792984426534502 0.011411570238062208
    # 0.00019242276185894578 0.0015004419435479368

    rects2 = ax.bar(ind + width, womenMeans, width,
                    color='#79c36a',
                    # path_effects=[path_effects.SimpleLineShadow(),
                    #               path_effects.Normal()],
                    align='center'
                    )
    # add some text for labels, title and axes ticks

    s = '%s' % ylabel

    if norm:
        s = '%s по отношению к %s' % (ylabel, languages[len(languages) - 1])

    if not units is '':
        s += ', %s' % units

    s += after_text

    ax.set_ylabel(s)
    ax.set_xlabel('Языки программирования')
    ax.set_title(title)
    ax.set_xticks(arange(len(womenMeans) + 1))

    if "Производительность" in title and not norm:
        plt.plot([0, len(languages) + 1], [1, 1], 'grey', alpha=0.25)

    #and len(womenMeans) < 12

    # if womenMeans[1] != int(womenMeans[1]):
    #     if not norm:
    #         if len(womenMeans) < 12:
    #             ax.set_xticklabels([""] + ["%.3f" % n for n in womenMeans])
    #         else:
    #             ax.set_xticklabels([""] + ["%.1f" % n for n in womenMeans])
    #     else:
    #         if len(womenMeans) < 17:
    #             ax.set_xticklabels([""] + ["%d" % (n * 100) + "%" for n in womenMeans])
    #         else:
    #             ax.set_xticklabels([""] + ["%d" % n for n in womenMeans])
    # else:
    #     ax.set_xticklabels([""] + ["%d" % n for n in womenMeans])

    ax.set_xticklabels([""] + list(languages), rotation='vertical')

    # ax.set_yticklabels([])

    # ax.set_xticks([])
    # min_data = min(womenMeans)
    # max_data = max(womenMeans)
    # delta = max_data - min_data;
    # l = len(womenMeans)
    # yticks = [(min_data + delta * i / l) for i in range(0, l)]
    # print(yticks)
    # ax.set_yticks(yticks)

    # ax.xaxis.set_visible(False)
    # ax.set_xticks(ind + width)
    # ax.set_xticklabels(languages)
    # ax.legend((rects2[0]), ('Men', 'Women'))

    def p(h):
        return h < 1

    def autolabel(rects):
        # attach some text labels
        for i, rect in enumerate(rects):
            height = rect.get_height()

            # if (p(height) or norm):

            # height = originalMeans[i]

            # if int(height) == height:
            #     text_height = "%d" % height
            # else:
            if norm:
                text_height = "%.3f" % height + "%"
            else:
                text_height = "%.3f" % height

            # text = ax.text(rect.get_x() + rect.get_width() / 2., height * 0.0,
            #                text_height,
            #                # weight='bold',
            #                ha='center', va='bottom', rotation='vertical', color='black',
            #                # size=16,
            #                # path_effects=[path_effects.Stroke(),
            #                #               path_effects.Normal()]
            #                )
            # # else:
            # text = ax.text(rect.get_x() + rect.get_width() / 2., height,
            #                "%.3f" % height,
            #                ha='center', va='center', rotation='horizontal', color='black', weight='bold',
            #                size=14,
            #                path_effects=[path_effects.Stroke(),
            #                              path_effects.Normal()])

    # autolabel(rects1)
    autolabel(rects2)

    # dpi=440
    fig.savefig(title.replace("\n", "") + ".png", bbox_inches='tight', dpi=120)
