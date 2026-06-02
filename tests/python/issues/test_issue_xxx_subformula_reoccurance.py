import unittest
import rtamt


class TestIssue164(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestIssue164, self).__init__(*args, **kwargs)

    def test_issue_online_xxx(self):
        spec1 = rtamt.StlDiscreteTimeOnlineSpecification()
        spec1.name = "RepeatedTemporalSubFormulas"
        spec1.declare_var("x", "int")
        spec1.spec = "F[0, 2] ( x > 5 )"
        spec2 = rtamt.StlDiscreteTimeOnlineSpecification()
        spec2.name = "RepeatedTemporalSubFormulas"
        spec2.declare_var("x", "int")
        spec2.spec = "F[0, 2] ( x > 5 ) and F[0, 2] ( x > 5 )"

        spec1.parse()
        spec1.pastify()
        rob1 = spec1.update(0, [('x', 5)])
        print(f"Robustness @0.0: {rob1}")
        spec2.parse()
        spec2.pastify()
        rob2 = spec2.update(0, [('x', 5)])
        print(f"Robustness @0.0: {rob2}")

        for var, time, val in [
            ("x", 1.0, 4),
            ("x", 2.0, 3),
            ("x", 3.0, 2),
            ("x", 4.0, 1),
            ("x", 5.0, 0),
        ]:
            print(f"{var} {time} {val}")
            rob1 = spec1.update(time, [(var, val)])
            rob2 = spec2.update(time, [(var, val)])
            print(f"Robustness @{time}: {rob1}")
            print(f"Robustness @{time}: {rob2}")


if __name__ == '__main__':
    unittest.main()