import traceback


def grade_all(name, begin, end, funcs):
    grade = 0
    for q in range(begin, end):
        func = funcs["grade_Q%d" % q]
        try:
            if func():
                print("============Q%d passed!============\n" % q)
                grade += 1
            else:
                print("============Q%d failed!============\n" % q)
        except Exception as e:
            print("============Q%d failed!============" % q)
            print(traceback.format_exc())
    print("Local Testing: %d functions passed" % grade)
    
    print("*************************************************************")
    print("* You may receive 0 points unless your code tests correctly *")
    print("* in CI System. Please commit and push your code to start.  *")
    print("*************************************************************")
