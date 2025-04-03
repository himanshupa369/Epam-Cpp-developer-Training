<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Function vs. Class Variadic Templates</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
            font-size: 18px;
            text-align: left;
        }
        th, td {
            padding: 12px;
            border: 1px solid #ddd;
        }
        th {
            background-color: #f4f4f4;
        }
    </style>
</head>
<body>
    <h2>Function vs. Class Variadic Templates</h2>
    <table>
        <tr>
            <th>Feature</th>
            <th>Function Variadic Template</th>
            <th>Class Variadic Template</th>
        </tr>
        <tr>
            <td>Purpose</td>
            <td>Allows functions to take a variable number of parameters</td>
            <td>Allows classes to take a variable number of template arguments</td>
        </tr>
        <tr>
            <td>Implementation</td>
            <td>Uses recursion or fold expressions</td>
            <td>Uses recursion with specializations</td>
        </tr>
        <tr>
            <td>Example Use</td>
            <td>Printing arguments, summing numbers</td>
            <td>Storing multiple types, tuple-like behavior</td>
        </tr>
        <tr>
            <td>Base Case</td>
            <td>Empty function overload</td>
            <td>Specialized empty class</td>
        </tr>
    </table>
</body>
</html>
