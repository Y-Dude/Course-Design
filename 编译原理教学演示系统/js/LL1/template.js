
//参数为   用户输入的上下文无关文法字符串数组
let cfgTemplate = function (cfg) {
    let temp = `<p>G[S]：</p>`;
    cfg.forEach(element => {
        temp = temp + `<p>&nbsp;&nbsp;&nbsp;${element}</p>`
    });
    return temp;
}

//参数一   存储first/follow信息的对象
//参数二   表示first集合还是follow集合  对应到表格的头部
let firstFollowTemplate = function (ffObj, ff) {
    let temp = `<table><tr><th colspan="2">${ff}</th></tr>`;
    for (let key in ffObj) {
        let value = [...ffObj[key]];
        temp = temp + `<tr><th>${key}</th><td>${value}</td></tr>`;
    }
    temp = temp + `</table>`
    return temp;
}

let ll1AnalysisTemplate = function (ll1AnalysisTable) {
    let flag = 0;
    let temp = `<h3>预测分析表</h3><table><tr><th rowspan="2">Vn(非终结符集合)</th><th colspan="${ll1AnalysisTable[0].length - 1}">Vt(终结符集合)</th></tr>`;
    ll1AnalysisTable.forEach((arr, index) => {
        if (index === 0) {
            temp = temp + `<tr>`;
            for (let value of arr) {
                temp = flag === 0 ? temp : temp + `<th>${value}</th>`;
                flag++;
            }
            flag = 0;
            temp = temp + `</tr>`;
        } else {
            temp = temp + `<tr>`;
            for (let value of arr) {
                temp = flag === 0 ? temp + `<th>${value}</th>` : temp + `<td>${value}</td>`;
                flag++;
            }
            temp = temp + `</tr>`;
            flag = 0;
        }
    });
    temp = temp + `</table>`;
    return temp;
}

let verifyAnalysisTemplate = function (verifyAnalysisTable) {
    let temp = `<h3>分析步骤</h3>`;

    verifyAnalysisTable.forEach((arr, index) => {
        let flag = 0;
        if (index === 0) {
            temp = temp + `<table><tr><th>步骤</th><th>分析栈</th><th>剩余输入串</th><th>推导所用产生式或匹配</th></tr>`;
        } else {
            temp = temp + `<tr>`;
            for (let value of arr) {
                temp = flag === 0 ? temp + `<th>${value}</th>` : temp + `<td>${value}</td>`;
                flag++;
            }
            temp = temp + `</tr>`;
            flag = 0;
        }
    });
    temp = temp + `</table>`
    return temp;
}