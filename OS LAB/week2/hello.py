from sympy import symbols
x, y, z = symbols('x y z')
expr = y + 2*x**2 + z**(-3)
expr2 = expr.subs(y, 2*x)
expr2