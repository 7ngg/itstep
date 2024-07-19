import { link } from "fs";
import { Link } from "react-router-dom";

type NavbarItem = {
  name: string;
  link: string;
};

interface navbarProps {
  items: NavbarItem[];
}

const Navbar = (props: navbarProps) => {
  return (
    <div className="h-12 bg-stone-800 text-white flex items-center justify-center gap-5 text-2xl">
      <Link
        to="/"
        className="py-1 px-5 hover:bg-stone-600 rounded duration-150"
      >
        Home
      </Link>
      {props.items.map((i, index) => (
        <Link
          key={index}
          to={i.link}
          className="py-1 px-5 hover:bg-stone-600 rounded duration-150"
        >
          {i.name}
        </Link>
      ))}
    </div>
  );
};

export default Navbar;
