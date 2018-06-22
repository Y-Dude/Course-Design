function stateTransitionTable(str,dict,terminals,edges) {
            // var dict = ["a", "b", "c"];
            // var terminals = [0, 2, 3];

            // var str = 'aababc';
            // var edges = [
            //     { src: 0, dest: 1, label: "a" },
            //     { src: 0, dest: 2, label: "b" },
            //     { src: 0, dest: 3, label: "c" },
            //     { src: 1, dest: 1, label: "a" },
            //     { src: 1, dest: 2, label: "b" },
            //     { src: 3, dest: 3, label: "c" }
            // ];

            let table = "";
            function max(arr) {
                let max = 0;
                for (let i = 0; i < arr.length; i++) {
                    if (arr[i].dest > max) {
                        max = arr[i].dest;
                    }
                }

                return max;
            }

            function doubleArr(x, y) {
                let arr = [];
                for (let i = 0; i < x; i++) {
                    arr[i] = {};
                    for (let j = 0; j < y; j++) {
                        arr[i][dict[j]] = -1;
                    }
                }
                return arr;
            }

            function analysisTable(Ltable) {
                terminals.forEach(index => {
                    for (let key in Ltable[index]) {
                        Ltable[index][key] = 'ε';
                    }
                });


                for (let i = 0; i < edges.length; i++) {
                    table[edges[i].src][edges[i].label] = edges[i].dest;
                }


            }

            function judge(string) {
                let strArr = string.split("");
                let state = [];
                let jumpto = 0;
                let i = 0;
                while (i < strArr.length) {
                    if (dict.indexOf(strArr[i]) === -1) {
                        state.push(-2);
                        break;
                    }

                    jumpto = table[jumpto][strArr[i]];
                    if (jumpto === 'ε' || jumpto === -1) {
                        state.push(-2);
                        break;
                    } else {
                        state.push(jumpto);
                    }
                    i++;

                }
                return state;
            }

            table = doubleArr(max(edges) + 1, dict.length);
            analysisTable(table);
            let pd = judge(str);


            return {
                stateTable: table,
                stateStacks: pd
            };
        }

function transitionTableTemplate (table,dict) {

    let temp = `<table><tr><th></th>`;
    for (value of dict) {
        temp = temp + `<th>${value}</th>`
    }
    temp = temp + `</tr>`;
    table.forEach( function(value, index) {
        temp = temp + `<tr><th>${index}</th>`
        for (key in value) {
            temp = temp + `<td>${value[key]}</td>`;
        }
        temp = temp + `</tr>`;
    });


    temp = temp + `</table>`;
    return temp;
}



function verify (minDfa) {

        var verifyStr = document.getElementById('verifyStr').value;
        verifyStr = verifyStr ? verifyStr : "aaa";
        var analysisResult = stateTransitionTable(verifyStr,minDfa.dict,minDfa.terminals,minDfa.edges);

        var template = transitionTableTemplate(analysisResult.stateTable,minDfa.dict);
        document.getElementById('trans-table').innerHTML = template;

        if (minDfa.terminals.indexOf(analysisResult.stateStacks[analysisResult.stateStacks.length-1]) === -1) {
          document.getElementById('tips').innerHTML = "验证失败，请重新输入";
        } else {
          document.getElementById('tips').innerHTML = "验证成功";
        }
}