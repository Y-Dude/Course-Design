var contain = document.querySelector('#main');
console.log(contain.offsetHeight);
console.log(contain.offsetWidth);
var stage = new Konva.Stage({
	container: 'main',
	width: contain.offsetWidth,
	height: contain.offsetHeight
});

var layer = new Konva.Layer();


var line1 = new Konva.Line({
	points: [100, 200, 200, 175, 300, 200],
	tension: 1,
	stroke: 'red',
	strokeWidth: 3
});
var line2 = new Konva.Line({
	points: [100, 200, 200, 225, 300, 200],
	tension: 1,
	stroke: 'red',
	strokeWidth: 3
});

var arrow1 = new Konva.Arrow({
	points: [100, 200, 290, 200],
	pointerLength: 10,
	pointerWidth: 10,
	stroke: 'black',
	strokeWidth: 4
});


var circle1 = new Konva.Circle({
	x: 100,
	y: 200,
	radius: 10,
	fill: 'blue'
});
var circle2 = new Konva.Circle({
	x: 300,
	y: 200,
	radius: 10,
	fill: 'blue',
	stroke: 'black',
	strokeWidth: 5
});


var circle3 = new Konva.Circle({
	radius: 100,
	fill: 'yellowgreen',
	stroke: 'black',
	strokeWidth: 1
});
var text = new Konva.Text({
	x: 0,
	y: 0,
	text: SOURCE,
	align: 'left',
	id: 'ykp'
});

var group = new Konva.Group({
	x: 500,
	y: 300,
	draggable: true
});
group.add(circle3);
group.add(text);



layer.add(line1);
layer.add(line2);
layer.add(arrow1);
layer.add(circle1);
layer.add(circle2);
layer.add(group);
stage.add(layer);