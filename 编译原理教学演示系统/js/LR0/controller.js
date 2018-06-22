Function.prototype.getMultilines = function () {
    return this.toString().slice(15, -4);
};
// set test data
document.addEventListener("DOMContentLoaded", function (event) {
    var inputGrammerDom = document.getElementById('input-grammar');
    inputGrammerDom.value = function () {/*E
E->aA
E->bB
A->cA
A->d
B->cB
B->d
*/}.getMultilines();

    var inputSentenceDom = document.getElementById('input-sentence');
    inputSentenceDom.value = 'bccd#';
});


function praseGrammar() {
    var inputGrammer = document.getElementById('input-grammar').value;

    initLR0Items(LR0Items, inputGrammer);
    var grammer = getAugmentedGrammar(LR0Items);  //获得 上下文无关文法的 扩展文法
    console.log("grammer====" + grammer);
    var resultItems = getItems(LR0Items);         //获得 dfa自动机所有状态数组
    var resultDfa = getDfaOutput(resultItems);
    window.lrPraseTable = getLrPraseTable(resultItems);  //构造  分析表
    console.log(lrPraseTable);
    var lrPraseTableString = formatLrPraseTable(lrPraseTable);  //格式化分析表 表格输出

    showGrammer(grammer);
    showDfa(resultDfa);
    showLrPraseTable(lrPraseTableString);



    function showGrammer(grammer) {
        grammer = grammer.replace(/\n/g, "<br>");
        document.getElementById('result-grammer').innerHTML = grammer;
    }

    function showDfa(resultDfa) {
        document.getElementById('result-dfa').innerHTML = Viz(resultDfa.dot);
    }

    function showLrPraseTable(lrPraseTableString) {
        var lrPraseTableDom = document.getElementById('result-parsetable');
        lrPraseTableDom.innerHTML = lrPraseTableString;
    }
}

function praseSentence() {
    var inputSentence = document.getElementById('input-sentence').value;
    if (window.lrPraseTable === undefined) {
        alert('请先生成 LRO 分析表');
        return;
    }

    var praseSentenceOutput = getPraseOutput(inputSentence, lrPraseTable, LR0Items.aug_productions);
    showSentenceOutput(praseSentenceOutput);

    function showSentenceOutput(praseSentenceOutput) {
        var sentenceOutputDom = document.getElementById('result-verifytable');
        sentenceOutputDom.innerHTML = praseSentenceOutput;
    }
}

function alertSentenceError() {
    alert(' 句子输入错误，请重新输入 ');
}

// // 如果 state 为空，句子出错
// if (state === undefined) {
//     alertSentenceError();
//     return;
// }
