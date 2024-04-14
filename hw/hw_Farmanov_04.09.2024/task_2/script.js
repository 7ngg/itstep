const tasks = [
    { text: 'Hit the gym', isCompleted: false },
    { text: 'Pay bills', isCompleted: false },
    { text: 'Meet John', isCompleted: false },
    { text: 'Buy eggs', isCompleted: false },
    { text: 'Read a book', isCompleted: false },
    { text: 'Organize office', isCompleted: false },
    { text: 'Eat dinner', isCompleted: false },
    { text: 'Buy apples', isCompleted: false },
    { text: 'Meet George', isCompleted: false },
    { text: 'Feed the cat', isCompleted: false },
    { text: 'Write a letter', isCompleted: false },
    { text: 'Run 1 km', isCompleted: false }
];

const listItem = document.querySelectorAll('.task');
const list = document.querySelector('#list');

function render() {
    list.innerHTML = '';
    let counter = 0; 
    tasks.forEach((task) => {
        let color = counter % 2 == 0 ? '#add8e6' : '#a5ccda';
        color = task.isCompleted ? '#e2e2e2' : color;
        const checkboxIcon = task.isCompleted ? '&#x2611' : '&#9744;';
        const isCompleted = task.isCompleted ? 'completed' : 'not-completed';

        list.insertAdjacentHTML(
            'beforeend',
            `
                <li class="task" style="background-color: ${color};">
                    <span class="checkbox" data-type="toggle" data-index="${counter}">${checkboxIcon}</span>
                    <span class="task-text ${isCompleted}">${task.text}</span>
                    <span class="remove-btn" data-type="remove" data-index="${counter}">&times;</span>
                </li>
            `);
        counter += 1;
    });
}

render()

list.onclick = function (event) {
    if (event.target.dataset.index) {
        const index = parseInt(event.target.dataset.index);
        const type = event.target.dataset.type;

        if (type === 'remove') {
            tasks.splice(index, 1);
        } else if (type === 'toggle') {
            tasks[index].isCompleted = !tasks[index].isCompleted;
        }
    }

    render()
}
