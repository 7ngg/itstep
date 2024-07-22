import { cardProps } from "../Components/ItemCard";
import data from "../data.json";

export enum Categories {
  All = 0,
  Electronics,
  Books,
  Furniture,
  Clothing,
  Toys,
  Garden,
  Health,
  Sports,
  Automotive,
  Beauty,
}

export function getData(category: Categories = Categories.All): cardProps[] {
  console.log("fetched data");

  const storeItems = data as cardProps[];

  if (category !== Categories.All) {
    return storeItems.filter((i) => i.category == category);
  }

  return storeItems;
}
