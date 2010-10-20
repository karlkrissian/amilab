# -*- coding: utf-8 -*-
re.sub(r"Pour\(([a-z]+),(.+),(.+)\)",r"for(\1=\2;\1<=\3;\1++)",test)

