import { Link } from "react-router-dom";

type Play = {
  name: string;
  link: string;
};

const listOfPlays: Play[] = [
  {
    name: "All's Well That Ends Well",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=allswell",
  },
  {
    name: "As You Like It",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=asyoulikeit",
  },
  {
    name: "Comedy of Errors",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=comedyerrors",
  },
  {
    name: "Love's Labour's Lost",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=loveslabours",
  },
  {
    name: "Measure for Measure",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=measure",
  },
  {
    name: "Merchant of Venice",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=merchantvenice",
  },
  {
    name: "Merry Wives of Windsor",
    link: "https://www.opensourceshakespeare.org/views/plays/playmenu.php?WorkID=merrywives",
  },
];

const Plays = () => {
  return (
    <div className="w-10/12 h-screen bg-gray-100 flex flex-col items-center py-5 gap-3">
      {listOfPlays.map((p, index) => (
        <Link
          key={index}
          to={p.link}
          className="w-10/12 shadow rounded p-2 hover:scale-105 transition hover:bg-stone-800 hover:text-white"
        >
          {p.name}
        </Link>
      ))}
    </div>
  );
};

export default Plays;
