const tasks = [
    'Hit the gym',
    'Pay bills',
    'Meet John',
    'Buy eggs',
    'Read a book',
    'Organize office',
    'Eat dinner',
    'Buy apples',
    'Meet George',
    'Feed the cat',
    'Write a letter',
    'Run 1 km'
];

const listItem = document.querySelectorAll('.task');
let counter = 0; 

listItem.forEach((task) => {
    task.style.backgroundColor = counter % 2 == 0 ? '#add8e6' : '#a5ccda';    
    counter += 1;
});
