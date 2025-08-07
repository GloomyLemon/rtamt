import unittest
import rtamt


class TestIssue164(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestIssue164, self).__init__(*args, **kwargs)

    def test_issue_online_xxx(self):
        spec = rtamt.StlDiscreteTimeOnlineSpecification()
        spec.name = "Bug?"
        spec.declare_var("x", "int")
        spec.declare_var("someVal", "int")
        spec.spec = "F[0, 2] ( x > 5 ) and F[0, 2] ( x > 5 )"
        # spec.spec = "F[0, 2] ( x > 5 )"

        spec.parse()
        spec.pastify()
        rob = spec.update(0, [('x', 5)])
        print(f"Robustness @0.0: {rob}")

        for var, time, val in [
            ("x", 1.0, 4),
            ("x", 2.0, 3),
            ("x", 3.0, 2),
            ("x", 4.0, 1),
            ("x", 5.0, 0),
        ]:
            print(f"{var} {time} {val}")
            rob = spec.update(time, [(var, val)])
            print(f"Robustness @{time}: {rob}")


if __name__ == '__main__':
    unittest.main()